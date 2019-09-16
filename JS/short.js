// shorthand js function declarations

var $h = () => {return document.head};
var $b = () => {return document.body};

var $new = (a) => {return document.createElement(a)};
var $new_id = (a, b) => {var c = document.createElement(a); c.id = b; return c;};

var $id = (a) => {return document.getElementById(a)};
var $class = (a) => {return document.getElementsByClassName(a)};

var $del = (a) => {a.parentNode.removeChild(a)};
