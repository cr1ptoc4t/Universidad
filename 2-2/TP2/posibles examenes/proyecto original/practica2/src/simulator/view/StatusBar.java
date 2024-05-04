package simulator.view;

import simulator.control.Controller;
import simulator.model.EcoSysObserver;
import simulator.model.animals.AnimalInfo;
import simulator.model.regionmanager.MapInfo;
import simulator.model.regionmanager.RegionInfo;

import javax.swing.*;
import java.awt.*;
import java.util.List;

class StatusBar extends JPanel implements EcoSysObserver {
    private Controller _ctrl;

    JLabel timeLabel, animalsLabel, dimensionLabel;

    StatusBar(Controller ctrl) {
        _ctrl = ctrl;
        initGUI();

        _ctrl.addObserver(this);
    }
    private void initGUI() {
        this.setLayout(new FlowLayout(FlowLayout.LEFT));
        this.setBorder(BorderFactory.createBevelBorder(1));

        createLabels();
    }

    private void createLabels() {
        timeLabel = new JLabel();
        animalsLabel = new JLabel();
        dimensionLabel = _ctrl.dimensionLabel();

        add(timeLabel);
        addSeparator();

        add(animalsLabel);
        addSeparator();

        add(dimensionLabel);
    }


    private void addSeparator(){
        JSeparator s = new JSeparator(JSeparator.VERTICAL);
        s.setPreferredSize(new Dimension(10, 20));
        this.add(s);
    }

    @Override
    public void onRegister(double time, MapInfo map, List<AnimalInfo> animals) {
        animalsLabel.setText("Total Animals: "+ animals.size());
        timeLabel.setText("Time: "+ time);
    }

    @Override
    public void onReset(double time, MapInfo map, List<AnimalInfo> animals) {
        animalsLabel.setText("Total Animals: "+ animals.size());
        timeLabel.setText("Time: " + String.format( "%.3f", time));
        dimensionLabel.setText("Dimension: " + map.get_width() + "x" + map.get_height() +
                " " + map.get_cols() + "x" + map.get_rows());
    }

    @Override
    public void onAnimalAdded(double time, MapInfo map, List<AnimalInfo> animals, AnimalInfo a) {
        animalsLabel.setText("Total Animals: "+ animals.size());
    }

    @Override
    public void onRegionSet(int row, int col, MapInfo map, RegionInfo r) {
    }

    @Override
    public void onAvanced(double time, MapInfo map, List<AnimalInfo> animals, double dt) {
        timeLabel.setText("Time: " + String.format( "%.3f", time));
        animalsLabel.setText("Total Animals: "+ animals.size());

    }
}
