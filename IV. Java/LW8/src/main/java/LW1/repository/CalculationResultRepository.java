package LW1.repository;

import LW1.model.CalculationResultEntity;
import org.springframework.data.repository.CrudRepository;
import org.springframework.stereotype.Repository;

@Repository
public interface CalculationResultRepository extends CrudRepository<CalculationResultEntity, Long> {
}

