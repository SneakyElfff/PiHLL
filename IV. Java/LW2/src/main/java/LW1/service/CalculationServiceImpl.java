package LW1.service;

import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.springframework.stereotype.Service;

import java.util.Arrays;

@Service    //enables Spring to provide the entity of this class if needed (using Dependency Injection)
public class CalculationServiceImpl implements LW1.service.CalculationService {
    private static final Logger log = LogManager.getLogger(CalculationServiceImpl.class);

    public Double findMean(Double num1, Double num2, Double num3, Double num4) {
        log.info("The mean value was calculated");    //in log4j2.xml logs are caught starting from the info level, while in code - from debug

        return (num1 + num2 + num3 + num4) / 4;
    }

    public Double findMedium(Double num1, Double num2, Double num3, Double num4) {
        Double[] nums = new Double[]{num1, num2, num3, num4};
        Arrays.sort(nums);

        log.info("The medium value was calculated");

        return ((nums[1] + nums[2]) / 2);
    }


}
