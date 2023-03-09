package LW1.service;

import org.springframework.stereotype.Service;
import java.util.Arrays;

@Service    //enables Spring to provide the entity of this class if needed (using Dependency Injection)
public class CalculationServiceImpl implements LW1.service.CalculationService
{
    public Double findMean(Double num1, Double num2, Double num3, Double num4)
    {
        return (num1 + num2 + num3 + num4) / 4;
    }
    public Double findMedium(Double num1, Double num2, Double num3, Double num4)
    {
        Double[] nums = new Double[] {num1, num2, num3, num4};
        Arrays.sort(nums);
        return ((nums[1] + nums[2]) / 2);
    }
}
