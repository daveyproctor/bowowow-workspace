<?php defined('SYSPATH') or die('No direct script access.');

class Controller_Hello extends Controller 
{
    public $template = 'site';
    
	public function action_index()
	{
	    //$this->template->message = 'hello, world!';
	    $this->response->body('hello, world!');
	}
}