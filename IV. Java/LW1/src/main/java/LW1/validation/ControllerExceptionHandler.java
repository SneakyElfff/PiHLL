package LW1.validation;

import java.util.Date;

import LW1.service.CalculationServiceImpl;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.MethodArgumentNotValidException;
import org.springframework.web.bind.annotation.ControllerAdvice;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.context.request.WebRequest;

@ControllerAdvice    //allows handling exceptions across the whole application in one global handling component
public class ControllerExceptionHandler {
    private static final Logger log = LogManager.getLogger(CalculationServiceImpl.class);

    @ExceptionHandler(MethodArgumentNotValidException.class)
    public ResponseEntity<ErrorMessage> customValidation(MethodArgumentNotValidException error) {
        ErrorMessage message = new ErrorMessage(
                HttpStatus.BAD_REQUEST.value(),
                new Date(),
                error.getMessage(),
                error.getBindingResult().getFieldError().getDefaultMessage());

        log.info("BAD_REQUEST_ERROR occurred");

        return new ResponseEntity<>(message, HttpStatus.BAD_REQUEST);
    }

    @ExceptionHandler(Exception.class)
    public ResponseEntity<ErrorMessage> globalExceptionHandler(Exception error, WebRequest request) {
        ErrorMessage message = new ErrorMessage(
                HttpStatus.INTERNAL_SERVER_ERROR.value(),
                new Date(),
                error.getMessage(),
                request.getDescription(false));

        log.info("INTERNAL_SERVER_ERROR occurred");

        return new ResponseEntity<>(message, HttpStatus.INTERNAL_SERVER_ERROR);
    }
}
