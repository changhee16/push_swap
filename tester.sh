CNT=100
INDEX=0
ITER=100
SUM=0
NUM_OVER=0
ARG=`jot -r $CNT -2147483648 2147483647 | tr "\n" " "`
NUM=`./push_swap $ARG | wc -l`
while [ $INDEX -lt $ITER ]
do
echo $ARG
echo "$INDEX	:	$NUM `./push_swap $ARG | ./checker_Mac $ARG`"
SUM=`expr $SUM + $NUM`
ARG=`jot -r $CNT -2147483648 2147483647 | tr "\n" " "`
NUM=`./push_swap $ARG | wc -l`
INDEX=`expr $INDEX + 1`
done
echo "[For $ITER times average: `expr $SUM / $ITER`]"
