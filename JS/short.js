// shorthand js function declarations
// import * as $ is intended, such that $.h will return the document head

export function h() {return document.head;};
export function b() {return document.body;};

export function create(type) {return document.createElement(type);};
export function createId(type, name) {var c = document.createElement(type); c.id = name; return c;};

export function byId(name) {return document.getElementById(name);};
export function byClass(clname) {return document.getElementsByClassName(clname);};

export function del(elem) {if (elem) elem.parentNode.removeChild(elem);};

export function empty(elem) {while (elem.childNodes.length > 0) { elem.removeChild(elem.childNodes[0]);} }; 
