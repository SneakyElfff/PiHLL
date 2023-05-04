package LW1.service;

import LW1.model.CalculationResultEntity;
import LW1.repository.CalculationResultRepository;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.cache.annotation.Cacheable;
import org.springframework.scheduling.annotation.Async;
import org.springframework.stereotype.Service;
import java.util.Arrays;
import java.util.concurrent.CompletableFuture;

@Service    //enables Spring to provide the entity of this class if needed (using Dependency Injection)
public class CalculationServiceImpl implements LW1.service.CalculationService {
    private static final Logger log = LogManager.getLogger(CalculationServiceImpl.class);
    @Autowired
    private CalculationResultRepository calcRepos;

    @Async    //allows to run method in a different stream
    @Cacheable(value = "meanResults")
    public CompletableFuture<CalculationResultEntity> findMean(Double num1, Double num2, Double num3, Double num4, Long id) {
//        try {    //slows down the request
//            log.info("Retrieving the calculations...");
//            Thread.sleep(5000);
//        } catch (InterruptedException e) {
//            e.printStackTrace();
//        }

        Double mean = (num1 + num2 + num3 + num4) / 4;

        CalculationResultEntity calcRes = new CalculationResultEntity(mean, 0.0);
        calcRes.setId(id);
        calcRepos.save(calcRes);

        log.info("The mean value was calculated");    //in log4j2.xml logs are caught starting from the info level, while in code - from debug

        return CompletableFuture.completedFuture(calcRes);
    }

    @Async
    @Cacheable(value = "mediumResults")
    public CompletableFuture<Double> findMedium(Double num1, Double num2, Double num3, Double num4) {
        Double[] nums = new Double[]{num1, num2, num3, num4};
        Double medium;

        Arrays.sort(nums);

        medium = (nums[1] + nums[2]) / 2;

        CalculationResultEntity calcRes = new CalculationResultEntity(0.0, medium);
        calcRepos.save(calcRes);

        log.info("The medium value was calculated");

        return CompletableFuture.completedFuture(medium);
    }
}
