import org.junit.Test;

import static org.junit.Assert.assertEquals;

public class AnimalTest {
    @Test
    public void test1(){
        Sheep s = new Sheep(1);

        assertEquals(s.getI(), 1);
    }
}
