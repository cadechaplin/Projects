import csv
class loan():
    loan_name = input("What the loan is for?")
    P = float(input("Principal loan amount:"))
    R = float(input("Yearly interest rate of the loan as a percent:"))/1200
    N = float(input("Number of years of the loan:"))
    A = float(input("Additional amount per month for accelerated schedule:"))
    MP = (R * P)/(1-pow((1+R),(-12*N)))


    def accelerated_schedule2(self):
        list = []
        i = 0
        ogP = self.P
        while i< 12*(self.N):

            SP = self.P
            self.P = self.P - (self.A + self.MP - (self.P * self.R))
            list.append( tuple([i +1 ,SP, self.A + self.MP, (self.A + self.MP - (SP * self.R)), (SP * self.R),  self.P]))
            i = i +1
        self.P = ogP
        return list

    def regular_schedule2(self):

        i = 0
        list = []
        ogP = self.P
        while i < 12*int(self.N):

            SP = self.P
            self.P = self.P - (self.MP - (self.P * self.R))
            list.append( tuple([i+1, SP, self.MP, (self.MP - (SP * self.R)), (SP * self.R),  self.P]))
            i = i +1
        self.P = ogP
        return list

myLoan= loan()
with open('accelerated_schedule.csv', 'w', newline='') as file:
    writer = csv.writer(file)

    writer.writerow(["Month",   "Starting_Balance", "Monthly_Payment", "Principal_Payment",   "Interest_Payment", "Ending_Balance"])
    writer.writerows(myLoan.accelerated_schedule2())

with open('regular_scedule.csv', 'w', newline='') as file:
    writer = csv.writer(file)

    writer.writerow(["Month",   "Starting_Balance", "Monthly_Payment", "Principal_Payment",   "Interest_Payment", "Ending_Balance"])
    writer.writerows(myLoan.regular_schedule2())