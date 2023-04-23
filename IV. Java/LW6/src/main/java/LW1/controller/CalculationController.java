package LW1.controller;

import LW1.actuator.CounterOfCalls;
import LW1.aggregation.Aggregation;
import LW1.model.Calculation;
import LW1.service.CalculationServiceImpl;
import jakarta.validation.Valid;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.*;
import LW1.service.CalculationService;

import java.util.ArrayList;
import java.util.List;
import java.util.stream.Collectors;

@RestController    //implements logics of client's requests
public class CalculationController {
    private final CalculationService obj;
    private final CounterOfCalls counter;

    @Autowired
    //enables Spring to implement dependency, so that Spring could send the object of Service realisation to Controller's constructor
    public CalculationController(CalculationService obj, CounterOfCalls counter) {
        this.obj = obj;
        this.counter = counter;
    }

    private static final Logger log = LogManager.getLogger(CalculationServiceImpl.class);

    @GetMapping(value = "/calc/mean/")    //sends requests to classes-controllers
    public ResponseEntity<Calculation> findMean(@Valid @RequestParam(name = "num1") Double num1, @Valid @RequestParam(name = "num2") Double num2, @Valid @RequestParam(name = "num3") Double num3, @Valid @RequestParam(name = "num4") Double num4) {
        log.info("Request received!");
        counter.incrementCounter();

        Calculation result = new Calculation(num1, num2, num3, num4, String.format("The mean value is %f", obj.findMean(num1, num2, num3, num4)));

        log.info("Data retrieved!");

        return result != null    //ResponseEntity - special class for returning responses
                ? new ResponseEntity<>(result, HttpStatus.OK)
                : new ResponseEntity<>(result, HttpStatus.BAD_REQUEST);
    }

    @GetMapping(value = "/calc/medium/")
    public ResponseEntity<Calculation> findMedium(@RequestParam(name = "num1") Double num1, @RequestParam(name = "num2") Double num2, @RequestParam(name = "num3") Double num3, @RequestParam(name = "num4") Double num4) {
        log.info("Request received!");
        counter.incrementCounter();

        Calculation result = new Calculation(num1, num2, num3, num4, String.format("The medium value is %f", obj.findMedium(num1, num2, num3, num4)));

        return result != null    //ResponseEntity - special class for returning responses
                ? new ResponseEntity<>(result, HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_FOUND);
    }

    @PostMapping(value = "/calc/mean/bulk/")
    public ResponseEntity<Object> findMeanBulk(@RequestBody List<Calculation> requests) {
        log.info("Bulk request received!");
        counter.incrementCounter();

        Aggregation aggregation1 = new Aggregation(requests);

        List<Calculation> results = requests.stream()    //method stream creates a stream of elements of the "results" list, which allows to work with elements of collections
                .filter(request -> request != null && request.getNum1() != null && request.getNum2() != null && request.getNum3() != null && request.getNum4() != null)
                .map(request -> new Calculation(
                        request,
                        String.format("The mean value is %f", obj.findMean(request.getNum1(), request.getNum2(), request.getNum3(), request.getNum4()))
                ))    //.map changes each element of the stream
                .collect(Collectors.toList());
        log.info("Data retrieved!");

        Aggregation aggregation2 = new Aggregation(results);

        List<Object> response = new ArrayList<>();
        response.add(results);
        response.add(aggregation1);
        response.add(aggregation2);
        return ResponseEntity.ok(response);
    }

    @PostMapping(value = "/calc/medium/bulk/")
    public ResponseEntity<List<Calculation>> findMediumBulk(@RequestBody List<Calculation> requests) {
        log.info("Bulk request received!");
        counter.incrementCounter();

        List<Calculation> results = requests.stream()
                .filter(request -> request != null && request.getNum1() != null && request.getNum2() != null && request.getNum3() != null && request.getNum4() != null)
                .map(request -> new Calculation(
                        request,
                        String.format("The medium value is %f", obj.findMedium(request.getNum1(), request.getNum2(), request.getNum3(), request.getNum4()))
                ))
                .collect(Collectors.toList());

        log.info("Data retrieved!");

        return new ResponseEntity<>(results, HttpStatus.OK);
    }
}
