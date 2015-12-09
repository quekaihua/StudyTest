<?php 
class userCD{
	protected $_user = NULL;
	
	public function setUser($user){
		$this->_user = $user;
	}
	
	public function getTitle(){
		$title = 'Waste of a Rib';
		return $title;
	}
}

class userCDInterpreter{
	protected $_user = NULL;
	
	public function setUser($user){
		$this->_user = $user;
	}
	
	public function getInterpreted(){
		$profile = $this->_user->getProfilePage();
		
		if(preg_match_all('/\{\{myCD\.(.*?)\}\}/',$profile,$triggers,PREG_SET_ORDER)){
			$replacements = array();
			
			foreach($triggers as $trigger){
				$replacements[] = $trigger[1];
			}
			
			$replacements = array_unique($replacements);
			
			$myCD = new userCD();
			$myCD->setUser($this->_user);
			
			foreach($replacements as $replacement){
				$profile = str_replace("{{myCD.{$replacement}}}",
							call_user_func(array($myCD,$replacement)),$profile);
			}
		}
		
		return $profile;
	}
}