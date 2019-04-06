# need_change 为需要找零的金额，
# currency_list 为该国货币的面值列表，
# num_list 为需要找零的最少货币数目, num_list的长度至少为(need_change+1)

def giveChange(need_change, currency_list, num_list, used_list):
    for change in range(need_change+1): #从0开始计算最少需要的货币数
        for currency in currency_list: #遍历每一种货币
            if (change-currency >= 0) and (num_list[change-currency]+1<=num_list[change]): #计算最少货币需求数
                num_list[change] = num_list[change-currency] + 1
                used_list[change] = currency #记录消耗的货币
    return
 
# 返回需要的货币
def showChange(need_change, used_list):
    give_list = []
    while need_change > 0:
        give_list.append(used_list[need_change])
        need_change -= used_list[need_change]
    give_list.sort() #排序
    return give_list
 
def main():
    need_change = 64 #需要找零的钱数
    currency_list = [1,5,10,21,25] # 该国的货币面值列表
    num_list = list(range(need_change+1)) #初始化num_list为0到need_change,共(need_change+1)个数
    used_list = list(range(need_change+1)) #初始化used_list为0到need_change,共(need_change+1)个数
    giveChange(need_change, currency_list, num_list, used_list)
    print("%d 需要 %d 个货币来找零"%(need_change, num_list[need_change]))
    give_list = showChange(need_change, used_list)
    print(give_list)
 
if __name__ == "__main__":
    main()