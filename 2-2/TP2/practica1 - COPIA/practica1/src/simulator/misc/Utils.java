package simulator.misc;

import java.util.Random;

public class Utils {
	public static final Random _rand = new Random();

	public static double constrain_value_in_range(double value, double min, double max) {
		value = value > max ? max : value;
		value = value < min ? min : value;
		return value;
	}

	public static double get_randomized_parameter(double value, double tolerance) {
		assert (tolerance > 0 && tolerance <= 1);
		double t = (_rand.nextDouble() - 0.5) * 2 * tolerance;
		return value * (1 + t);
	}

	public static double estabilizar(double var, int min, int max){
		if(var>max) var=max;
		else if (var<min) var=min;
		return var;
	}
}
