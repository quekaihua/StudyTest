/**
 * Created by Administrator on 2015/12/22.
 */
function getXHR(){
    var req;
    if(window.XMLHttpRequest){
        req = new XMLHttpRequest();
    }else if(window.ActiveXObject){
        req = new ActiveXObject("Microsoft.XMLHTTP");
    }
    return req;
}