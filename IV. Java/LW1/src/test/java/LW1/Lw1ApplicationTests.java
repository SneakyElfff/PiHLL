package LW1;

import LW1.service.CalculationService;
import LW1.service.CalculationServiceImpl;
import org.junit.Assert;
import org.junit.Before;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;

import java.util.Arrays;

@SpringBootTest
class Lw1ApplicationTests {
    private static final Double a = 1.0;
    private static final Double b = 3.0;
    private static final Double c = 5.0;
    private static final Double d = 7.0;

    private static final Logger log = LogManager.getLogger(CalculationServiceImpl.class);

    CalculationServiceImpl obj = new CalculationServiceImpl();

    @Test
    public void testFindMean() {
        Double result = 4.0;

        Assert.assertEquals("(1+3+5+7) / 4 must be equal to 4", result, obj.findMean(a, b, c, d));

        log.info("Mean value found: {}", obj.findMean(a, b, c, d));
        log.info("Mean value found: {}", obj.findMean(a, b, c, d));
    }

    @Test
    public void testFindMedium() {
        Double result = 4.0;

        Assert.assertEquals("(3+5) / 2 must be equal to 4", result, obj.findMedium(a, b, c, d));

        log.info("Medium value found: {}", obj.findMedium(a, b, c, d));
    }

}
