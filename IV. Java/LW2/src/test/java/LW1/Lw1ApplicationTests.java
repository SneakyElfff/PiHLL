package LW1;

import LW1.service.CalculationService;
import LW1.service.CalculationServiceImpl;
import org.junit.Assert;
import org.junit.Before;
import org.junit.jupiter.api.Test;
import org.springframework.boot.test.context.SpringBootTest;

import java.util.Arrays;

@SpringBootTest
class Lw1ApplicationTests
{
	Double a = 1.0;
	Double b = 3.0;
	Double c = 5.0;
	Double d = 7.0;

	CalculationService obj = new CalculationService() {
		@Override
		public Double findMean(Double num1, Double num2, Double num3, Double num4) {
			return (num1 + num2 + num3 + num4) / 4;
		}

		@Override
		public Double findMedium(Double num1, Double num2, Double num3, Double num4) {
			Double[] nums = new Double[] {num1, num2, num3, num4};
			Arrays.sort(nums);

			return ((nums[1] + nums[2]) / 2);
		}
	};

	@Before
	public void setUp()
	{
		a = 1.0;
		b = 3.0;
		c = 5.0;
		d = 7.0;

		CalculationService obj = new CalculationService() {
			@Override
			public Double findMean(Double num1, Double num2, Double num3, Double num4) {
				return (num1 + num2 + num3 + num4) / 4;
			}

			@Override
			public Double findMedium(Double num1, Double num2, Double num3, Double num4) {
				Double[] nums = new Double[] {num1, num2, num3, num4};
				Arrays.sort(nums);

				return ((nums[1] + nums[2]) / 2);
			}
		};
	}

	@Test
	public void testFindMean()
	{
		Double result = 4.0;
		
		Assert.assertEquals("(1+3+5+7) / 4 must be equal to 4", result, obj.findMean(a, b, c, d));
	}

	@Test
	public void testFindMedium()
	{
		Double result = 4.0;

		Assert.assertEquals("(3+5) / 2 must be equal to 4", result, obj.findMedium(a, b, c, d));
	}

}
