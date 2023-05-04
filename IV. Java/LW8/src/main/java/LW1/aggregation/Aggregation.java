package LW1.aggregation;

import LW1.model.Calculation;
import LW1.service.CalculationServiceImpl;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.springframework.stereotype.Component;
import java.util.DoubleSummaryStatistics;
import java.util.List;
import java.util.stream.DoubleStream;

@Component
public class Aggregation {
    private String type;
    private Double min;
    private Double max;
    private Double average;

    private static final Logger log = LogManager.getLogger(CalculationServiceImpl.class);

    public Aggregation(List<Calculation> data) {
        DoubleSummaryStatistics stats;

        if (!data.isEmpty() && data.get(0).getMessage() != null) {
            type = "Statistics for output:";
            stats = data.stream()
                    .mapToDouble(stat -> Double.parseDouble(stat.getMessage().substring(stat.getMessage().lastIndexOf(" ") + 1)))
                    .summaryStatistics();    //creates a DoubleSummaryStatistics object, which prepares statistics for a stream of values
        } else {
            type = "Statistics for input:";
            stats = data.stream()
                    .flatMapToDouble(stat -> DoubleStream.of(
                            stat.getNum1(),
                            stat.getNum2(),
                            stat.getNum3(),
                            stat.getNum4()
                    ))
                    .summaryStatistics();
        }

        this.min = stats.getMin();
        this.max = stats.getMax();
        this.average = stats.getAverage();

        log.info("Statistical data is sent");
    }

    public void setType(String type) {
        this.type = type;
    }

    public void setMin(Double min) {
        this.min = min;
    }

    public void setMax(Double max) {
        this.max = max;
    }

    public void setAverage(Double average) {
        this.average = average;
    }

    public String getType() {
        return type;
    }

    public double getMin() {
        return min;
    }

    public double getMax() {
        return max;
    }

    public double getAverage() {
        return average;
    }
}