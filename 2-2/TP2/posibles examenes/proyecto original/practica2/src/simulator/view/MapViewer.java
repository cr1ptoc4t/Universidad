package simulator.view;

import simulator.model.animals.Animal;
import simulator.model.animals.AnimalInfo;
import simulator.model.animals.State;
import simulator.model.regionmanager.MapInfo;

import java.awt.*;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.geom.Rectangle2D;
import java.util.Collection;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;

@SuppressWarnings("serial")
public class MapViewer extends AbstractMapViewer {

	// Anchura/altura/ de la simulación -- se supone que siempre van a ser iguales
	// al tamaño del componente
	private int _width;
	private int _height;

	// Número de filas/columnas de la simulación
	private int _rows;
	private int _cols;

	// Anchura/altura de una región
	int _rwidth;
	int _rheight;

	// Mostramos sólo animales con este estado.
	private State _currState;
	int state=1;

	private static final String helpTextH = "h: toggle help";
	private static final String helpTextS = "s: show animals of a specific state";

	// En estos atributos guardamos la lista de animales y el tiempo que hemos
	// recibido la última vez para dibujarlos.
	volatile private Collection<AnimalInfo> _objs;
	volatile private Double _time;

	// Una clase auxilar para almacenar información sobre una especie
	private static class SpeciesInfo {
		private Integer _count;
		private Color _color;

		SpeciesInfo(Color color) {
			_count = 0;
			_color = color;
		}
		public int getCount(){return _count;}
		public void setCount(int i){_count=i;}

	}

	// Un mapa para la información sobre las especies
	Map<String, SpeciesInfo> _kindsInfo = new HashMap<>();

	// El font que usamos para dibujar texto
	private Font _font = new Font("Arial", Font.BOLD, 12);

	// Indica si mostramos el texto la ayuda o no
	private boolean _showHelp;

	public MapViewer() {
		initGUI();
	}

	private void initGUI() {
		addKeyListener(new KeyAdapter() {
			@Override
			public void keyPressed(KeyEvent e) {
				switch (e.getKeyChar()) {
				case 'h':
					_showHelp = !_showHelp;
					repaint();
					break;
				case 's':
					cambiaEstado();
					repaint();
				default:
				}
			}

		});

		addMouseListener(new MouseAdapter() {

			@Override
			public void mouseEntered(MouseEvent e) {
				requestFocus(); // Esto es necesario para capturar las teclas cuando el ratón está sobre este
								// componente.
			}
		});

		// Por defecto mostramos todos los animales
		_currState = null;

		// Por defecto mostramos el texto de ayuda
		_showHelp = true;
	}


	private void cambiaEstado() {
		int num_etapas= State.values().length+1;
		if(state%num_etapas==0)
			_currState = null;
		else
			_currState = State.values()[state%num_etapas -1];

		state++;
	}

	@Override
	protected void paintComponent(Graphics g) {
		super.paintComponent(g);

		Graphics2D gr = (Graphics2D) g;
		gr.setRenderingHint(RenderingHints.KEY_ANTIALIASING, RenderingHints.VALUE_ANTIALIAS_ON);
		gr.setRenderingHint(RenderingHints.KEY_TEXT_ANTIALIASING, RenderingHints.VALUE_TEXT_ANTIALIAS_ON);

		// Cambiar el font para dibujar texto
		g.setFont(_font);

		// Dibujar fondo blanco
		gr.setBackground(Color.WHITE);
		gr.clearRect(0, 0, _width, _height);

		// Dibujar los animales, el tiempo, etc.
		if (_objs != null)
			drawObjects(gr, _objs, _time);

		if(_showHelp){
			g.setColor(Color.red);
			g.drawString(helpTextH, 10, 15);
			g.drawString(helpTextS, 10, 30);
		}

	}

	private boolean visible(AnimalInfo a) {
		return _currState==null || a.get_state()==_currState;
	}

	private void drawObjects(Graphics2D g, Collection<AnimalInfo> animals, Double time) {

		super.paintComponent(g); //paint background
		paintGrid(g);

		// Dibujar los animales
		for (AnimalInfo a : animals) {
			// Si no es visible saltamos la iteración
			if (!visible(a))
				continue;

			// La información sobre la especie de 'a'
			SpeciesInfo esp_info = _kindsInfo.get(a.get_genetic_code());

			if(esp_info==null){
				esp_info = new SpeciesInfo(ViewUtils.get_color(a.get_genetic_code()));
				_kindsInfo.put(a.get_genetic_code(), esp_info);
			}

			//  Incrementar el contador de la especie
			esp_info._count++;

			// Dibujar el animal en la posicion correspondiente
			g.setColor(esp_info._color);
			g.fillRoundRect((int)a.get_position().getX(), (int)a.get_position().getY(),(int) (a.get_age()/2)+2, (int)(a.get_age()/2)+2, 6, 6);
		}


		// Dibujar la etiqueta del estado visible, sin no es null.
		if(_currState!=null){
			g.setColor(Color.BLACK);
			drawStringWithRect(g, _width -50, 20, _currState.toString());
		}

		// Dibuja la etiqueta del tiempo
		g.setColor(Color.BLUE);
		drawStringWithRect(g, 20, _height-20, "Time: "+ String.format("%.3f", _time));

		// Dibujar la información de todas la especies.
		int title_height = _height -20;
		for (Entry<String, SpeciesInfo> e : _kindsInfo.entrySet()) {
			String key = e.getKey();
			g.setColor(ViewUtils.get_color(key));
			drawStringWithRect(g, 20, title_height-=20, key + ": " + e.getValue().getCount());
			e.getValue().setCount(0);
		}
	}

	// Un método que dibujar un texto con un rectángulo
	void drawStringWithRect(Graphics2D g, int x, int y, String s) {
		Rectangle2D rect = g.getFontMetrics().getStringBounds(s, g);
		g.drawString(s, x, y);
		g.drawRect(x - 1, y - (int) rect.getHeight(), (int) rect.getWidth() + 1, (int) rect.getHeight() + 5);
	}

	private void paintGrid(Graphics2D g){
		for (int i = 0; i < _width; i +=_rheight)
			g.drawLine(i, 0, i, _height);

		for (int i = 0; i < _height; i += _rwidth)
			g.drawLine(0, i, _width, i);

	}

	@Override
	public void update(List<AnimalInfo> objs, Double time) {
		update_aux(objs, time);
	}

	@Override
	public void reset(double time, MapInfo map, List<AnimalInfo> animals) {
		_width = map.get_width();
		_height = map.get_height();
		_cols = map.get_cols();
		_rows = map.get_rows();

		_rwidth= map.get_region_width();
		_rheight= map.get_region_height();

		// Esto cambia el tamaño del componente, y así cambia el tamaño de la ventana
		// porque en MapWindow llamamos a pack() después de llamar a reset
		setPreferredSize(new Dimension(_width, _height));
		// Dibuja el estado
		update_aux(animals, time);
	}

	private void update_aux (List<AnimalInfo> animals, double time) {
		_objs=animals;
		_time=time;
		repaint();
	}
}
