import React, { Component,Autolinker} from 'react';

class TravelPage extends Component {
    _getData(id) {
        var self = this;
        return this.props.route.database.ref('/posts/' + id).once('value').then(function(snapshot) {
            self.setState({data:snapshot.val()});
        });
    }

    constructor(props) {
      super(props);
      this.state = {id:"", data:[], mapSvg:null, planeSvg:null};

      this.props.route.firebase.auth().signInWithEmailAndPassword("matthieubessol@gmail.com", "thehiker").catch(function(error) {
        console.log("error")
      });
    }

    componentWillMount() {
        this.setState({id:this.props.params.travelId});
        this._getData(this.props.params.travelId);
    }

    render() {
        var svgMap = (<div>Loading svg</div>);
        var htmlObject = document.createElement('div');
        if(this.state.data) {
            svgMap = this.state.data.mapSVG;
        }
        return (
            <div className="TravelPage">
                I m travel page
                <div dangerouslySetInnerHTML={{__html: svgMap}} />
            </div>
        )
    }
}

export default TravelPage;
