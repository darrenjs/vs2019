

def list_example():

     # create a list
     ccys = []

     # add some items
     ccys.append("GBP")
     ccys.append("NZD")
     ccys.append("CHF")
     ccys.append("EUR")
     ccys.append("CAD")

     # print size
     print("number of ccys: {}".format(len(ccys)))

     # print our each item
     for item in ccys:
         print(item)

     # test existence
     if 'JPY' in ccys:
         print("we have JPY")
     else:
        print("missing JPY")

     # remove items
     ccys.remove('CAD')

     # print size
     print("number of ccys: {}".format(len(ccys)))



list_example()


