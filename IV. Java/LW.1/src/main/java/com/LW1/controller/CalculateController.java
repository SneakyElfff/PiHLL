package com.LW1.controller;

import com.LW1.model.Calculate;
import com.LW1.service.Methods;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.PathVariable;
import org.springframework.web.bind.annotation.RestController;

@RestController    //this class provides the logics for processing of clients' requests
public class CalculateController
{
    private final Methods methods;

    @Autowired    //adds dependency
    public CalculateController(Methods methods)
    {
        this.methods = methods;
    }

    @GetMapping(value = "/calculations/{num1}/{num2}/{num3}/{num4}")    //processes GET-requests
    public ResponseEntity<Double> findMean(@PathVariable(name = "num1") int num1, @PathVariable(name = "num2") int num2, @PathVariable(name = "num3") int num3, @PathVariable(name = "num4") int num4)
    {
        double resultMean = Methods.findMean(num1, num2, num3, num4);

        return new ResponseEntity<>(resultMean, HttpStatus.OK);
    }

    @GetMapping(value = "/calculations/{num1}/{num2}/{num3}/{num4}")    //processes GET-requests
    public ResponseEntity<Double> findMedium(@PathVariable(name = "num1") int num1, @PathVariable(name = "num2") int num2, @PathVariable(name = "num3") int num3, @PathVariable(name = "num4") int num4)
    {
        final Double resultMedium = Methods.findMedium(num1, num2, num3, num4);

        return new ResponseEntity<>(resultMedium, HttpStatus.OK);
    }
}
