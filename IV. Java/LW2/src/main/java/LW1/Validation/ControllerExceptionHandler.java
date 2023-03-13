package LW1.Validation;

import java.util.Date;

import LW1.service.CalculationServiceImpl;
import org.apache.logging.log4j.LogManager;
import org.apache.logging.log4j.Logger;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.MethodArgumentNotValidException;
import org.springframework.web.bind.annotation.ControllerAdvice;
import org.springframework.web.bind.annotation.ExceptionHandler;
import org.springframework.web.client.HttpClientErrorException;
import org.springframework.web.context.request.WebRequest;

@ControllerAdvice
public class ControllerExceptionHandler
{
    private static final Logger log = LogManager.getLogger(CalculationServiceImpl.class);

    @ExceptionHandler(Exception.class)
    public ResponseEntity<ErrorMessage> GlobalExceptionHandler(Exception error, WebRequest request)
    {
        ErrorMessage message = new ErrorMessage(
                HttpStatus.INTERNAL_SERVER_ERROR.value(),
                new Date(),
                error.getMessage(),
                request.getDescription(false));

        log.info("INTERNAL_SERVER_ERROR occurred");

        return new ResponseEntity<ErrorMessage>(message, HttpStatus.INTERNAL_SERVER_ERROR);
    }

    @ExceptionHandler(HttpClientErrorException.NotFound.class)
    public ResponseEntity<ErrorMessage> NotFoundException(Exception error, WebRequest request) {
        ErrorMessage message = new ErrorMessage(
                HttpStatus.NOT_FOUND.value(),
                new Date(),
                error.getMessage(),
                request.getDescription(false));

        log.info("NOT_FOUND_ERROR occurred");

        return new ResponseEntity<ErrorMessage>(message, HttpStatus.NOT_FOUND);
    }

    @ExceptionHandler(MethodArgumentNotValidException.class)
    public ResponseEntity<?> customValidation(MethodArgumentNotValidException error)
    {
        ErrorMessage message = new ErrorMessage(
                HttpStatus.BAD_REQUEST.value(),
                new Date(),
                error.getMessage(),
                error.getBindingResult().getFieldError().getDefaultMessage());

        log.info("BAD_REQUEST_ERROR occurred");

        return new ResponseEntity<>(message, HttpStatus.BAD_REQUEST);
    }
}
