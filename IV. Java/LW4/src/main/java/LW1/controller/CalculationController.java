package LW1.controller;

import LW1.actuator.CounterOfCalls;
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

//    @RequestMapping(value = "/calc")
//    @PostMapping
//    public ResponseEntity<String> valid(@Valid @RequestBody Calculation calc)
//    {
//        return ResponseEntity.ok("valid");
//    }

    @GetMapping(value = "/calc/mean/{num1}/{num2}/{num3}/{num4}")    //sends requests to classes-controllers
    public ResponseEntity<Calculation> findMean(@Valid @PathVariable(name = "num1") Double num1, @Valid @PathVariable(name = "num2") Double num2, @Valid @PathVariable(name = "num3") Double num3, @Valid @PathVariable(name = "num4") Double num4) {
        log.info("Request received!");
        counter.incrementCounter();

        Calculation result = new Calculation();    //to crash the program - final Calculation result = null;
        result.setNum1(num1);
        result.setNum2(num2);
        result.setNum3(num3);
        result.setNum4(num4);

        result.setMessage(String.format("The mean value is %f", obj.findMean(num1, num2, num3, num4)));

        log.info("Data retrieved!");

        return result != null    //ResponseEntity - special class for returning responses
                ? new ResponseEntity<>(result, HttpStatus.OK)
                : new ResponseEntity<>(result, HttpStatus.BAD_REQUEST);
    }

    @GetMapping(value = "/calc/medium/{num1}/{num2}/{num3}/{num4}")
    public ResponseEntity<Calculation> findMedium(@PathVariable(name = "num1") Double num1, @PathVariable(name = "num2") Double num2, @PathVariable(name = "num3") Double num3, @PathVariable(name = "num4") Double num4) {
        log.info("Request received!");
        counter.incrementCounter();

        Calculation result = new Calculation();
        result.setNum1(num1);
        result.setNum2(num2);
        result.setNum3(num3);
        result.setNum4(num4);

        result.setMessage(String.format("The medium value is %f", obj.findMedium(num1, num2, num3, num4)));

        return result != null    //ResponseEntity - special class for returning responses
                ? new ResponseEntity<>(result, HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_FOUND);
    }
}
