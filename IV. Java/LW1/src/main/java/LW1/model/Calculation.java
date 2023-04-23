package LW1.model;

import jakarta.validation.constraints.Min;

public class Calculation {
    @Min(0)
    private Double num1;
    @Min(0)
    private Double num2;
    @Min(0)
    private Double num3;
    @Min(0)
    private Double num4;
    private String message;

    public Calculation() {
    }

    public Calculation(Double num1, Double num2, Double num3, Double num4, String message) {
        this.num1 = num1;
        this.num2 = num2;
        this.num3 = num3;
        this.num4 = num4;
        this.message = message;
    }

    public Calculation(Calculation obj, String message) {
        this.num1 = obj.num1;
        this.num2 = obj.num2;
        this.num3 = obj.num3;
        this.num4 = obj.num4;
        this.message = message;
    }

    public Double getNum1() {
        return num1;
    }

    public void setNum1(Double num1) {
        this.num1 = num1;
    }

    public Double getNum2() {
        return num2;
    }

    public void setNum2(Double num2) {
        this.num2 = num2;
    }

    public Double getNum3() {
        return num3;
    }

    public void setNum3(Double num3) {
        this.num3 = num3;
    }

    public Double getNum4() {
        return num4;
    }

    public void setNum4(Double num4) {
        this.num4 = num4;
    }

    public String getMessage() {
        return message;
    }

    public void setMessage(String message) {
        this.message = message;
    }
}
