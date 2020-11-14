package Test;


import bsu.Exponential;
import bsu.Liner;
import org.junit.Assert;
import org.junit.Before;
import org.junit.Test;

public class SeriesTest {
    Liner liner;
    Exponential exponential;

    @Before
    public void setUp() {
        liner = new Liner(0.5, 7. / 4);
        exponential = new Exponential(2.3, -2);
    }

    @Test
    public void countElem() {
        Assert.assertEquals(liner.countElem(5), (0.5 + 4 * 7. / 4), 0.0);
    }
}