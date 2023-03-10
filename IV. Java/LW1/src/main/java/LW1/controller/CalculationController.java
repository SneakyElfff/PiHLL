package LW1.controller;

import LW1.model.Calculation;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;
import LW1.service.CalculationService;

@RestController    //implements logics of client's requests
public class CalculationController
{
    private final CalculationService obj;

    @Autowired    //enables Spring to implement dependency, so that Spring could send the object of Service realisation to Controller's constructor
    public CalculationController(CalculationService obj)
    {
        this.obj = obj;
    }

    @GetMapping(value = "/calc/mean/{num1}/{num2}/{num3}/{num4}")
    public ResponseEntity<Calculation> findMean(@PathVariable(name = "num1") Double num1, @PathVariable(name = "num2") Double num2, @PathVariable(name = "num3") Double num3, @PathVariable(name = "num4") Double num4)
    {
        Calculation result = new Calculation();
        result.setNum1(num1);
        result.setNum2(num2);
        result.setNum3(num3);
        result.setNum4(num4);

        result.setMessage(String.format("The mean value is %f", obj.findMean(num1, num2, num3, num4)));

        return result != null    //ResponseEntity - special class for returning responses
                ? new ResponseEntity<>(result, HttpStatus.OK)
                : new ResponseEntity<>(HttpStatus.NOT_FOUND);
    }

    @GetMapping(value = "/calc/medium/{num1}/{num2}/{num3}/{num4}")
    public ResponseEntity<Calculation> findMedium(@PathVariable(name = "num1") Double num1, @PathVariable(name = "num2") Double num2, @PathVariable(name = "num3") Double num3, @PathVariable(name = "num4") Double num4)
    {
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
