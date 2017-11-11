<?php
namespace Home\Controller;
use Think\Controller;
use Home\Service\ProjectService;
use Think\Upload;
class IndexController extends Controller {

    protected $model;
    protected $service;

    public function __construct(){
        parent::__construct();
        $this->model = M('project');
        $this->service = new ProjectService;
    }

    public function index(){
        $list = $this->model->select();
        $this->assign('list', $list);
        $this->display();
    }

    public function show_add(){
        $this->display('edit');
    }

    public function add(){
        $pname = I('post.pname');
        $has_pname = $this->model->where(array('project_name'=>$pname))->find();
        if($has_pname){
            $this->ajaxReturn(apiFail('已经存在此项目'));
        }
        set_time_limit(0);
        ini_set('memory_limit', '512M');
        ini_set('post_max_size', '1024M');
        ini_set('upload_max_filesize', '1024M');
        ini_set('max_input_time', '3200');
        ini_set('max_execution_time', '3200');

        $this->service->create($pname);
        $data['project_name'] = $pname;
        $data['create_time'] = date("Y-m-d H:i:s");
        $res = $this->model->add($data);
        if($res){
            $this->ajaxReturn(apiSuccess('操作成功'));
        }else{
            $this->ajaxReturn(apiFail('操作失败'));
        }
    }

    public function test(){
        set_time_limit(0);
        ini_set('max_input_time', '3200');
        ini_set('max_execution_time', '3200');
        $this->service->create('test');
    }
}