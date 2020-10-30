dat = read.table(file="text.txt", dec=",")
d=dat[,1]
dat_table = table(dat)
dat_frame = as.data.frame(dat_table)
dat_frame[, 3] = 100 * dat_table / (sum(dat_table))
dat_frame[, 4] = cumsum(dat_table)
dat_frame[, 5] = cumsum(dat_frame[, 3])
colnames(dat_frame) = c("Value", "Frequency", "Frequence", "Cumulative frequency",
                      "Cumulative frequence")
dat_frame
plot(dat_table, type="l", main="Частотный полигон", xlab="Значение", ylab="Частота")
values = sort(d)
values_unique = unique(values)
cumulative_frequency_values = as.numeric(dat_frame[, 4])
cumulative_frequency_values
plot(values_unique,cumulative_frequency_values,type="l",xlab="значение",ylab="накопленная частота", main= "Кумулята
абсолютных частот")