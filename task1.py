
Name = input("Please enter your Name: ")
DailyStepGoal = (float)(input("Please enter yor Daily step goal: "))
totalSteps = 0
while(totalSteps<DailyStepGoal):
    StepsWalked = (int)(input("Enter steps walked(or 0 to finish): "))
    if StepsWalked == 0 :
        break
    totalSteps += StepsWalked
    reminingSteps = DailyStepGoal - totalSteps
    if(totalSteps>=DailyStepGoal):
        print("Amazing! You passed your goal!")
        break
    elif reminingSteps<500 :
        print("Almost there!")
        print("You have ",reminingSteps," Steps left to reach your goal")
    elif(totalSteps<DailyStepGoal):
        print("You have ",reminingSteps," Steps left to reach your goal")
        

Percentage = (totalSteps/DailyStepGoal)*100
print("Total Steps Walked = ",totalSteps)
print("Percentage of the goal achieved = ",Percentage)
print("Keep going and you can always achieve your goal!")