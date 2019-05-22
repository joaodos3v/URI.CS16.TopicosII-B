import React from 'react';
import { Text, View } from 'react-native';
import HabitosList from '../components/HabitosList';

import habitosJson from '../../habitos.json';
import { ScrollView } from 'react-native-gesture-handler';

export default class HabitosPage extends React.Component {
	constructor(props) {
		super(props);

		this.state = {
			habitos: []
		};
	}

	componentDidMount() {
		this.setState({
			habitos: habitosJson
		});
	}
	
	renderList() {
		const ret = this.state.habitos.map(habito => {
			const { id, nome } = habito;
			return <Text key={ id }>{ id } - { nome }</Text>
		});

		return ret;
	}

	render() {
		return (
			<ScrollView>
				<HabitosList habitos={ this.state.habitos } />
      		</ScrollView>
		);
	}
}
