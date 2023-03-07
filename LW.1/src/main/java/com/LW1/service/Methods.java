package com.LW1.service;

import org.springframework.stereotype.Service;

import java.util.Arrays;

@Service    //lets Spring provide a coder with a class object if needed using Dependency Injection
public class Methods
{
    public static double findMean(int num1, int num2, int num3, int num4)
    {
        return (num1 + num2 + num3 + num4) / 4;
    }
    public static double findMedium(int num1, int num2, int num3, int num4)
    {
        int[] nums = new int[] {num1, num2, num3, num4};
        Arrays.sort(nums);
        return (nums[1] + nums[2]) / 2;
    }
}
