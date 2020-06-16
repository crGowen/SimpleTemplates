// shorthand js function declarations

export $h = () => {return document.head};
export $b = () => {return document.body};

export $new = (type) => {return document.createElement(type)};
export $new_id = (type, name) => {var c = document.createElement(type); c.id = name; return c;};

export $id = (name) => {return document.getElementById(name)};
export $class = (clname) => {return document.getElementsByClassName(clname)};

export $del = (elem) => {if (elem) elem.parentNode.removeChild(elem)};

export $empty = (elem) => {while (elem.childNodes.length > 0) {elem.removeChild(elem.childNodes[0]);}}; 
