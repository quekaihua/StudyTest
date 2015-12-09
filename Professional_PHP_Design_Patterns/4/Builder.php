<?
class product{
	protected $_type = '';
	protected $_size = '';
	protected $_color = '';
	
	public function setType($type){
		$this->_type = $type;
	}
	
	public function setSize($size){
		$this->_size = $size;
	}
	
	public function setColor($color){
		$this->_color = $color;
	}
}

class productBulder{
	protected $_product = NULL;
	protected $_configs = array();
	
	public function __construct($configs){
		$this->_product = new product();
		$this->_configs = $configs;
	}
	
	public function buil(){
		$this->_product->setType($this->_configs['size']);
		$this->_product->setType($this->_configs['type']);
		$this->_product->setColor($this->_configs['color']);
	}
	
	public function getProduct(){
		return $this->_product;
	}
}

$productConfigs = array('size'=>10,'type'=>'forwheel','color'=>'yellow');
$builder = new productBulder($productConfigs);
$builder->buil();
$product = $builder->getProduct();