dat = read.table('text.txt', col.names = c("X", "Y"),dec = ',')
dat

plot(dat, type='p', main='Корреляционное поле', xlab='X', ylab='Y')





courseDisp = var(dat[,1])
courseStdev = sqrt(courseDisp)
courseMean = mean(dat[,1])


table = rep(0, 3 * 4)
dim(table) = c(3, 4)
table = as.data.frame(table)
table

courses = dat[,1]
firstSigmaValues = subset(courses, ((courseMean - courseStdev) < courses)& (courses < (courseMean + courseStdev)))
secondSigmaValues = subset(courses, ((courseMean - 2 * courseStdev) < courses)& (courses < (courseMean + 2 * courseStdev)))
thirdSigmaValues = subset(courses, ((courseMean - 3 * courseStdev) < courses& courses < (courseMean + 3 * courseStdev)))

table
table[1, 1] = '(mean - sigma, mean + sigma)'
table[2, 1] = '(mean - 2sigma, mean + 2sigma)'
table[3, 1] = '(mean - 3sigma, mean + 3sigma)'

table[1, 2] = length(firstSigmaValues)
table[2, 2] = length(secondSigmaValues)
table[3, 2] = length(thirdSigmaValues)

table[1, 3] = table[1, 2] / length(courses)
table[2, 3] = table[2, 2] / length(courses)
table[3, 3] = table[3, 2] / length(courses)

table[1, 4] = 0.683
table[2, 4] = 0.954
table[3, 4] = 0.997
table






groups = 1 + floor(log2(length(courses)))
groups

range = max(courses) - min(courses)
step = range / groups

coursesSort = sort(courses)

table = rep(0, groups * 5)
dim(table) = c(groups, 5)
table = as.data.frame(table)
table

for (i in 0:(groups - 1)) {
  left = coursesSort[1] + i * step
  right = left + step
  group = subset(dat[,2], left <= courses
                 & (courses < right | i == groups - 1 & courses <= right))
  table[i + 1, 1:5] = c(left, right, length(group), sum(group), mean(group))
}
table




x = length(courses) - 2
coefCor = cor(courses, dat[,2])
coefCor




levelCor = abs(coefCor) * sqrt(x / (1 - coefCor ^ 2))
levelCor





abline(lm(dat[,2] ~ dat[,1]))

