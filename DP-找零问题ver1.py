# need_change 为需要找零的金额，
# currency_list 为该国货币的面值列表，
# num_list 为需要找零的最少货币数目, num_list的长度至少为(need_change+1)
def giveChange(need_change, currency_list, num_list):
    for change in range(need_change+1): #从0开始计算最少需要的货币数
        for currency in currency_list: #遍历每一种货币
            if (change-currency >= 0) and (num_list[change-currency]+1<num_list[change]): #计算最少货币需求数
                num_list[change] = num_list[change-currency] + 1
    return
import time
def main():
    t1=time.clock()
    need_change = 63
    currency_list = [1,5,10,21,25]
    num_list = list(range(need_change+1)) #初始化num_list为0到need_change,共(need_change+1)个数
    giveChange(need_change, currency_list, num_list)
    print("%d 需要 %d 个货币来找零"%(need_change, num_list[need_change]))
    t2=time.clock()
    print("耗时:"+str(t2-t1))
if __name__ == "__main__":
    main()