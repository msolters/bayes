# bayes
Bayesian inference sandbox in C

u know wat it is
```
make bayes && ./bayes
```

Basically, we're adding data points to an array of fixed length.  Each time we add a data point we update the `mu` and `kappa` of our gamma-normal distribution.  At the end (after loading all the data) we print out the final `mu` our model has converged on.

You can experiment adding many data points that are close together, then a few outliers, to see how/to what extent the gamma-normal is resilient to rogue data.
