package com.LW1.model;

public class Calculate {
    private int id;
    private double num1;
    private double num2;
    private double num3;
    private double num4;

    public Calculate(int id, double new_num1, double new_num2, double new_num3, double new_num4)
    {
        this.id = id;
        this.num1 = new_num1;
        this.num2 = new_num2;
        this.num3 = new_num3;
        this.num4 = new_num4;
    }

    public int getId()
    {
        return id;
    }

    public double getNum1()
    {
        return num1;
    }

    public double getNum2()
    {
        return num2;
    }

    public double getNum3()
    {
        return num3;
    }

    public double getNum4()
    {
        return num4;
    }

    public void setId(int new_id)
    {
        this.id = id;
    }

    public void setNum1(int new_num1)
    {
        this.num1 = new_num1;
    }

    public void setNum2(int new_num2)
    {
        this.num2 = new_num2;
    }

    public void setNum3(int new_num3)
    {
        this.num3 = new_num3;
    }

    public void setNum4(int new_num4)
    {
        this.num4 = new_num4;
    }

}
