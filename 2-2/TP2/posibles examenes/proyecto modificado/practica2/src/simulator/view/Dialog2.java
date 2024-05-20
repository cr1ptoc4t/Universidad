package simulator.view;

import simulator.control.Controller;
import simulator.model.EcoSysObserver;
import simulator.model.animals.AnimalInfo;
import simulator.model.regionmanager.MapInfo;
import simulator.model.regionmanager.RegionInfo;

import javax.swing.*;
import java.awt.*;
import java.util.List;

public class Dialog2 extends JDialog implements EcoSysObserver {

    Controller _ctrl;
    Frame _parent;
    public Dialog2(Controller ctrl, Frame parent){
        super((Frame) null, true);
        this._parent = parent;
        this._ctrl = ctrl;
        initGUI();
        this._ctrl.addObserver(this);
    }

    private void initGUI(){
        JPanel mainpanel = new JPanel();
        add(mainpanel);
        mainpanel.add(new JLabel("run has just ended"));

        setPreferredSize(new Dimension(500,500));

        pack();
        setResizable(false);
        setVisible(false);
    }

    @Override
    public void onRegister(double time, MapInfo map, List<AnimalInfo> animals) {

    }

    @Override
    public void onReset(double time, MapInfo map, List<AnimalInfo> animals) {

    }

    @Override
    public void onAnimalAdded(double time, MapInfo map, List<AnimalInfo> animals, AnimalInfo a) {

    }

    @Override
    public void onRegionSet(int row, int col, MapInfo map, RegionInfo r) {

    }

    @Override
    public void onAvanced(double time, MapInfo map, List<AnimalInfo> animals, double dt) {

    }
}
