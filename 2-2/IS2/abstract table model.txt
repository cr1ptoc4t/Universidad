package proyectoIS.view;

import proyectoIS.modelo_de_dominio.Vehiculo;

import javax.swing.table.AbstractTableModel;
import java.util.ArrayList;
import java.util.List;

public class VehiculosModelTable extends AbstractTableModel {
    String[] _headers = {"Matricula", "Tipo", "Modelo"};
    List<Vehiculo> vehiculos;

    public VehiculosModelTable() {
        vehiculos = new ArrayList<Vehiculo>();
    }

    @Override
    public int getRowCount() {
        return vehiculos.size();
    }

    @Override
    public int getColumnCount() {
        return _headers.length;
    }

    @Override
    public Object getValueAt(int rowIndex, int columnIndex) {
        Object ret = null;
        Vehiculo vehiculo = vehiculos.get(rowIndex);
        switch (columnIndex) {
            case 0:
                ret = vehiculo.get_matricula();
                break;
            case 1:
                ret = vehiculo.get_tipo_vehiculo();
                break;
            case 2:
                ret = vehiculo.get_modelo();
        }
        return ret;
    }
}
