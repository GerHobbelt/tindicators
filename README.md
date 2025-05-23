[![Build Status](https://travis-ci.com/TulipCharts/tulipindicators.svg?branch=master)](https://travis-ci.com/TulipCharts/tulipindicators)

# T-indicators

**tindicators** is a library of technical analysis indicators. It 
provides over 160 indicators and is blazing fast.

**tindicators** is a fork of the original [**Tulip Indicators**](https://tulipindicators.org).

## Introduction

T-Indicators is a library of technical analysis functions written in ANSI C.


## Features

 - **C99 with no dependencies**.
 - Uses fast algorithms.
 - Easy to use programming interface.
 - Release under LGPL license.


## Building

Building is easy. You only need a decent C compiler. T-Indicators has no
other dependencies.

Just download the code and run `make`.

```
git clone https://github.com/TulipCharts/tulipindicators
cd tulipindicators
make
```

You should get a static library, `libindicators.a`. You'll need that library
and the header file `indicators.h` to use Tulip Indicators in your code.


## Not Building

If you don't want to build the library, you can simply add the
`tiamalgamation.c` file to your project, along with `indicators.h` and
`candles.h`. The amalgamation file contains all of Tulip Indicators - you don't
actually need any of the other source files.

This is the recommended method to import Tulip Indicators into code for
bindings to other languages, since it makes it very easy to update versions.

## Usage

For usage information, please see:
[https://tulipindicators.org/usage](https://tulipindicators.org/usage)


## Indicator Listing
```
104 total indicators

Overlay
   avgprice            Average Price
   bbands              Bollinger Bands
   dema                Double Exponential Moving Average
   ema                 Exponential Moving Average
   hma                 Hull Moving Average
   kama                Kaufman Adaptive Moving Average
   linreg              Linear Regression
   medprice            Median Price
   psar                Parabolic SAR
   sma                 Simple Moving Average
   tema                Triple Exponential Moving Average
   trima               Triangular Moving Average
   tsf                 Time Series Forecast
   typprice            Typical Price
   vidya               Variable Index Dynamic Average
   vwma                Volume Weighted Moving Average
   wcprice             Weighted Close Price
   wilders             Wilders Smoothing
   wma                 Weighted Moving Average
   zlema               Zero-Lag Exponential Moving Average

Indicator
   ad                  Accumulation/Distribution Line
   adosc               Accumulation/Distribution Oscillator
   adx                 Average Directional Movement Index
   adxr                Average Directional Movement Rating
   ao                  Awesome Oscillator
   apo                 Absolute Price Oscillator
   aroon               Aroon
   aroonosc            Aroon Oscillator
   atr                 Average True Range
   bop                 Balance of Power
   cci                 Commodity Channel Index
   cmo                 Chande Momentum Oscillator
   cvi                 Chaikins Volatility
   di                  Directional Indicator
   dm                  Directional Movement
   dpo                 Detrended Price Oscillator
   dx                  Directional Movement Index
   emv                 Ease of Movement
   fisher              Fisher Transform
   fosc                Forecast Oscillator
   kvo                 Klinger Volume Oscillator
   linregintercept     Linear Regression Intercept
   linregslope         Linear Regression Slope
   macd                Moving Average Convergence/Divergence
   marketfi            Market Facilitation Index
   mass                Mass Index
   mfi                 Money Flow Index
   mom                 Momentum
   msw                 Mesa Sine Wave
   natr                Normalized Average True Range
   nvi                 Negative Volume Index
   obv                 On Balance Volume
   ppo                 Percentage Price Oscillator
   pvi                 Positive Volume Index
   qstick              Qstick
   roc                 Rate of Change
   rocr                Rate of Change Ratio
   rsi                 Relative Strength Index
   stoch               Stochastic Oscillator
   stochrsi            Stochastic RSI
   tr                  True Range
   trix                Trix
   ultosc              Ultimate Oscillator
   vhf                 Vertical Horizontal Filter
   volatility          Annualized Historical Volatility
   vosc                Volume Oscillator
   wad                 Williams Accumulation/Distribution
   willr               Williams %R

Math
   crossany            Crossany
   crossover           Crossover
   decay               Linear Decay
   edecay              Exponential Decay
   lag                 Lag
   max                 Maximum In Period
   md                  Mean Deviation Over Period
   min                 Minimum In Period
   stddev              Standard Deviation Over Period
   stderr              Standard Error Over Period
   sum                 Sum Over Period
   var                 Variance Over Period

Simple
   abs                 Vector Absolute Value
   acos                Vector Arccosine
   add                 Vector Addition
   asin                Vector Arcsine
   atan                Vector Arctangent
   ceil                Vector Ceiling
   cos                 Vector Cosine
   cosh                Vector Hyperbolic Cosine
   div                 Vector Division
   exp                 Vector Exponential
   floor               Vector Floor
   ln                  Vector Natural Log
   log10               Vector Base-10 Log
   mul                 Vector Multiplication
   round               Vector Round
   sin                 Vector Sine
   sinh                Vector Hyperbolic Sine
   sqrt                Vector Square Root
   sub                 Vector Subtraction
   tan                 Vector Tangent
   tanh                Vector Hyperbolic Tangent
   todeg               Vector Degree Conversion
   torad               Vector Radian Conversion
   trunc               Vector Truncate

```


## Special Thanks

The stochrsi indicator was sponsored by: [Gunthy](https://gunthy.org).

The candle pattern recognition was sponsored by: [Algorum](https://algorumsoftware.com)


#### Motivation

The goal of this project was to create a library of indicators that would be fast, complete and easy to integrate into other systems. It is based on a fork of [tulipindicators](http://github.com/tulipcharts/tulipindicators). 

#### Contribution

Design overview and contribution guidelines: [CONTRIBUTING.md](./CONTRIBUTING.md)
