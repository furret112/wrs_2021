var ros = new ROSLIB.Ros({
  url : 'ws://localhost:9090'
});

ros.on('connection', function() {
  console.log('Connected to websocket server.');
});

ros.on('error', function(error) {
  console.log('Error connecting to websocket server: ', error);
});

ros.on('close', function() {
  console.log('Connection to websocket server closed.');
});

// Publishing a Topic
// ------------------

var table = new ROSLIB.Topic({
  ros : ros,
  name : '/recieve_html',
  messageType : '/html_test/html_msg'
});


function myFunction(table_number){
  if (table_number == 1)
  {
    var num = 1;
  }
  else if (table_number == 2)
  {
    var num = 2;
  }
  else if (table_number == 3)
  {
    var num = 3;
  }
  else if (table_number == 4)
  {
    var num = 4;
  }
  else if (table_number == 5)
  {
    var num = 5
  }
  else if (table_number == 6)
  {
    var num = 6
  }  

  var id_table = new ROSLIB.Message({
  id : num
  });

  table.publish(id_table);
}