import { createAppContainer, createStackNavigator } from 'react-navigation';
import HabitosPage from './src/pages/HabitosPage';

const AppNavigator = createStackNavigator(
  {
    'Main': {
      screen: HabitosPage,
      navigationOptions: {
        title: 'Hábitos',
        headerTitleStyle: {
          textAlign: 'left',
          fontSize: 20
        }
      }
    }
  },
  {
    defaultNavigationOptions: {
      title: "MyHabitTimeline",
      headerTintColor: "white",
      headerStyle: {
        backgroundColor: '#6542f4',
        borderBottomColor: '#f4f2ff',
      },
      headerTitleStyle: {
        color: 'white',
        fontSize: 20,
        flexGrow: 1,
        textAlign: 'center',
      }
    }
  }
);

const AppContainer = createAppContainer(AppNavigator);

export default AppContainer;