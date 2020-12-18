dat=read.table("text.txt",dec=',')
buffer <-dat[,1]
dat[,1]<- dat[,2]
dat[,2]<-buffer



y <-dat[,2] 
Average_Level_Of_A_Number_Of_Dynamics <- sum(y)/length(y)



t <- 1.96
buffer<-c(1:36)
for (i in 1:36) {
  if(y[i]>Average_Level_Of_A_Number_Of_Dynamics) {
    buffer[i] <- 1
  } else {
    buffer[i] <-0
  }
}
count<-1
for (i in 2:36) {
  if(buffer[i-1] != buffer[i]){
    count <- count + 1
  }
}
LeftEdge <-(length(y)+1-t*sqrt(length(y)-1))/2
RightEdeg <-(length(y)+1+t*sqrt(length(y)-1))/2



YAfterLiquefaction <-c(1:36)

YAfterLiquefaction[1]<- ((5*y[1]+2*y[2]-y[3])/6)

YAfterLiquefaction[36]<- ((5*y[36]+2*y[35]-y[34])/6)

for (i in 2:35) {
  YAfterLiquefaction[i] <- (y[i-1]+y[i]+y[i+1])/3
}




a0<-mean(y)
n<-length(y)
time<- (1:n) - round(n/2)
time<- time- round((n:1)/n)
timeDat<- time*dat[,2]
time2<-time*time
a1<-sum(timeDat)/sum(time2)




dat[,2]<-y
plot(dat,col="red")
lines(dat, col="red")

dat[,2]<-YAfterLiquefaction
points(dat,col="green")
lines(dat, col="green")

points(dat[,1],a1*time+a0,col="blue")
lines(dat[,1],a1*time+a0,col="blue")

