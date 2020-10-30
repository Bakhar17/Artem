dat <- read.table("f.txt", dec = ",")
d <- dat[,1]
d
mean(d)
disp <- var(d)
disp
sd(d)
sqrt(disp)
which.max(table(d))
median(d)
a <- table(d)
a
zn <- sort(unique(d))
zn
sr_znach <- mean(d)
sr_znach
n <- length(d)
n
srednekvadr <- sd(d)
srednekvadr
koeff_assim <- sum((zn - sr_znach)^3 * a)/(n * srednekvadr^3)
koeff_assim
sr_znach <- mean(d)
sr_znach
n <- length(d)
n
srednekvadr <- sd(d)
srednekvadr
koeff_assim <- sum((d - sr_znach)^3)/(n * srednekvadr^3)
koeff_assim
skewness(d)
kurtosis(d)
