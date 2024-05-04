package simulator.view;

public class VelocityData {
    String _genetic_code;
    Double _vel_med;

    public VelocityData(String gen, Double med){
        _genetic_code = gen;
        _vel_med = med;
    }

    public Object getValueAt(int columnIndex) {
        return columnIndex==0?_genetic_code:( String.format("%.3f", _vel_med));
    }
}
