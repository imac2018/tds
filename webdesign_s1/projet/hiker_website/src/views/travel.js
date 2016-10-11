import React, { Component,} from 'react';

class Travel extends Component {
    constructor(props) {
      super(props);
      this.state = {};

      this.props.route.firebase.auth().signInWithEmailAndPassword("matthieubessol@gmail.com", "thehiker").catch(function(error) {
        console.log("error")
      });
      console.log(this.props.route)
    }

    render() {
        // var self = this;
        return (
            <div className="Travel">
                I m travel
            </div>
        )
    }
}

export default Travel;
