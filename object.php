<?php

    //cast it to an object
    $my_object = (object) ["key" => "value"];
    //print($my_object);
    echo $my_object->key + "\n";
  
    
class Foo { 
    public $aMemberVar = 'aMemberVar Member Variable'; 
    public $aFuncName = 'aMemberFunc'; 
    
    
    function aMemberFunc() { 
        print 'Inside `aMemberFunc()`'; 
    } 
} 

$foo = new Foo; 

$element = 'aMemberVar'; 
print $foo->$element . "\n"; // prints "aMemberVar Member Variable" 


    
    
    
    
    
    
    
    
    // $my_object->key("value1");
    // //print($value1 . "\n");
    
    // //print($value2 . "\n");
    // $value3 = $my_object["key"];
    // print($value3 . "\n");
?>