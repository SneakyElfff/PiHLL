package LW1.service;

import LW1.model.CalculationResultEntity;

import java.util.concurrent.CompletableFuture;
import java.util.concurrent.Future;

public interface CalculationService {
    CompletableFuture<CalculationResultEntity> findMean(Double num1, Double num2, Double num3, Double num4, Long id);

    CompletableFuture<Double> findMedium(Double num1, Double num2, Double num3, Double num4);
}
