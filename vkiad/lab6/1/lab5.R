d = read.table(file = "text.txt",dec=',')

plot(d, type = "p", 
     main = "Диаграмма рассеивания", 
     xlab = "X", ylab = "Y",
     col = "red", pch = 20, cex = 2)


cl = kmeans(scale(d), 2)
table(cl$cluster)


cl$centers


sapply(1:2, function(i) cl$centers[,i] * sd(d[,i]) + mean(d[,i]))

plot(d, col = c("blue", "red")[cl$cluster], pch = 20, cex = 2, xlab = "X", ylab = "Y", main = "2 clusters")
legend("bottomleft", legend = c("1", "2"), fill = c("blue", "red"))

plot(d, pch = (1:2)[cl$cluster], cex = 2, xlab = "X", ylab = "Y", main = "2 clusters")
legend("bottomleft", legend = c("1", "2"),pch = 1:2)


#Число кластеров = 3
cl = kmeans(scale(d), 3)
#Число наблюдений
table(cl$cluster)

cl$centers

sapply(1:2, function(i) cl$centers[,i] * sd(d[,i]) + mean(d[,i]))

plot(d, col = c("blue", "green", "red")[cl$cluster], pch = 20, cex = 2, xlab = "X", ylab = "Y", main = "3 clusters")
legend("bottomleft", legend = c("1", "2", "3"), fill = c("blue", "green", "red"))

plot(d, pch = (1:3)[cl$cluster], cex = 2, xlab = "X", ylab = "Y", main = "3 clusters")
legend("bottomleft", legend = c("1", "2", "3"),pch = 1:3)

