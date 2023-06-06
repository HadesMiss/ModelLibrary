## Getting Started with Create React App

This project was bootstrapped with [Create React App](https://github.com/facebook/create-react-app), using the [Redux](https://redux.js.org/) and [Redux Toolkit](https://redux-toolkit.js.org/) TS template.



~~~c
npm start
~~~

Runs the app in the development mode.\
Open [http://localhost:3000](http://localhost:3000) to view it in the browser.

The page will reload if you make edits.\
You will also see any lint errors in the console.

~~~c
npm test
~~~

Launches the test runner in the interactive watch mode.\
See the section about [running tests](https://facebook.github.io/create-react-app/docs/running-tests) for more information.

~~~c
npm run build
~~~

Builds the app for production to the `build` folder.\
It correctly bundles React in production mode and optimizes the build for the best performance.

The build is minified and the filenames include the hashes.\
Your app is ready to be deployed!

See the section about [deployment](https://facebook.github.io/create-react-app/docs/deployment) for more information.
~~~c
 `npm run eject`
~~~
**Note: this is a one-way operation. Once you `eject`, you can’t go back!**

If you aren’t satisfied with the build tool and configuration choices, you can `eject` at any time. This command will remove the single build dependency from your project.

Instead, it will copy all the configuration files and the transitive dependencies (webpack, Babel, ESLint, etc) right into your project so you have full control over them. All of the commands except `eject` will still work, but they will point to the copied scripts so you can tweak them. At this point you’re on your own.

You don’t have to ever use `eject`. The curated feature set is suitable for small and middle deployments, and you shouldn’t feel obligated to use this feature. However we understand that this tool wouldn’t be useful if you couldn’t customize it when you are ready for it.

### Learn More

### Available Scripts

### In the project directory, you can run:

#### In the project directory

#### In the project directory
python
~~~python

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
import matplotlib

matplotlib.rc("font", family='DengXian')

df = pd.read_excel(
    r'F:\研究生学习\编程学习\Python\Geographic_Indicators\可视化分析\指标汇总_20230210\052-055赫芬达尔指数\052-055赫芬达尔指数\output\res.xls',
    header=None)
print(df.iloc[0])

currIndustry = ""
currArr = [[], []]

for index in range(len(df)):
    currItem = df.iloc[index]
    if currItem[3] == currIndustry:
        # 行业名 年份 赫芬达尔
        currArr[0].append(currItem[1])
        currArr[1].append(currItem[4])
    else:
        if currIndustry != "":
            # dist[currIndustry] = currArr
            plt.plot(currArr[0], currArr[1])
            plt.title(currIndustry)
            plt.xlabel("时间/年")
            plt.ylabel("赫芬达尔指数")
            plt.ylim(0, 1)
            plt.savefig('./image/' + currIndustry + '.jpg')
            plt.clf()
            currArr = [[], []]
        currIndustry = currItem[3]
        currArr[0].append(currItem[1])
        currArr[1].append(currItem[4])
#python
###python
##python

~~~

The lift coefficient ($C_L$) is a dimensionless coefficient.

* Lists
* [ ] todo
* [x] done

A table:

| a   | b   |
| --- | --- |

You can learn more in the [Create React App documentation](https://facebook.github.io/create-react-app/docs/getting-started).

To learn React, check out the [React documentation](https://reactjs.org/).

