
# importing necessary libraries
import pandas as pd
import numpy as np
from sklearn import linear_model
import matplotlib.pyplot as plt


df = pd.read_csv('data.csv')    # upload data
print(df)

DATA = df.loc[:,['x','z']].values
result= df.loc[:,['results']].values

# learn the model
reg = linear_model.LinearRegression()
reg.fit(DATA,result)

#prediction
predicted_Y = reg.predict(DATA)
#print('predicted results for all DATA colum is:', predicted_Y)


# Y= a(x) + b(z) + c
coefficients= reg.coef_
interception = reg.intercept_

print('coef is', coefficients)            # coeffiecents
print('intercept_ is ' , interception)       # interception


# СЃР»СѓС‡Р°Р№РЅС‹Рµ Р·РЅР°С‡РµРЅРёСЏ X Рё Z.
#               ([[ X,  Z]])
S = reg.predict([[0.6, 1.1]])   # predicted y
print('РџСЂРµРґСЃРєР°Р·Р°РЅРёРµ Y :',S )