package LW1.actuator;

import LW1.service.CalculationServiceImpl;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.springframework.stereotype.Component;

import java.util.concurrent.atomic.AtomicInteger;

@Component
public class CounterOfCalls {
    private static volatile AtomicInteger counter;
    private static final Logger log = LogManager.getLogger(CalculationServiceImpl.class);

    public CounterOfCalls() {
        counter = new AtomicInteger(0);
    }

    public synchronized int getCounter() {
        log.info("Current number of calls: %d".formatted(counter.get()));
        return counter.get();
    }

    public synchronized void incrementCounter() {
        log.info("Updated number of calls: %d".formatted(counter.incrementAndGet()));
    }
}