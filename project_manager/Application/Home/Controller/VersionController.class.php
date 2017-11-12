<?php
namespace Home\Controller;
use Think\Controller;
use Home\Service\ProjectService;
use Think\Upload;
class VersionController extends Controller {

    protected $model;
    protected $service;

    public function __construct(){
        parent::__construct();
        $this->model = M('project_version');
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

    public function show_pro(){
        $pid = I('get.pid');
        if(!$pid){
            $this->error('参数错误');
        }
        $where['pid'] = $pid;
        $list = $this->model->where($where)->select();
        $this->assign(array(
            "pid" => I("get.pid"),
            "list" => $list
        ));
        $this->display('show_pro');
    }

    public function add(){
        //todo
        $pid = I('post.pid');
        $data['pid'] = $pid;
        $data['create_time'] = date("Y-m-d H:i:s");
        $res = $this->model->add($data);
        if($res){
            $this->ajaxReturn(apiSuccess('操作成功'));
        }else{
            $this->ajaxReturn(apiFail('操作失败'));
        }

        $version = I('post.version');
        $desc = I('post.desc');

        $has_version = $this->model->where(array('version'=>$version))->find();
        if($has_version){
            $this->error('已经存在此版本');
//            $this->ajaxReturn(apiFail('已经存在此项目'));
        }
        $data['project_name'] = $pname;
        $data['desc'] = $desc;
        $data['create_time'] = date("Y-m-d H:i:s");
        $res = $this->model->add($data);
        if($res){
            $this->success('操作成功');
//            $this->ajaxReturn(apiSuccess('操作成功'));
        }else{
            $this->error('操作失败');
//            $this->ajaxReturn(apiFail('操作失败'));
        }
    }

    public function upload(){
        $pid = I('get.pid');
        $version = I('get.version');
        $upload = new Upload();// 实例化上传类
        $upload->maxSize   =     3145728 ;// 设置附件上传大小
        $upload->exts      =     array('zip');// 设置附件上传类型
        $upload->rootPath  =     './Public/Uploads/'; // 设置附件上传根目录
        $upload->savePath  =     ''; // 设置附件上传（子）目录
        // 上传文件 
        $info   =   $upload->upload();
        if(!$info) {// 上传错误提示错误信息
            $this->error($upload->getError());
        }else{// 上传成功
            $data['upload'] = $upload->rootPath . $info['myfile']['savepath'].$info['myfile']['savename'];
            $where['pid'] = $pid;
            $where['id'] = $version;
            $this->model->where($where)->save($data);
            $this->success('上传成功！');
        }
    }

    public function build(){
        $pid = I('get.pid');
        $version = I('get.version');
        $where['pid'] = $pid;
        $where['project_version.id'] = $version;
        $project = $this->model
                    ->join("project on project_version.pid=project.id")
                    ->where($where)
                    ->find();
        $src = $project['upload'];
        $project_name = $project['project_name'];
        // $dst = $this->service->get_project_assets_path($project_name, $version);
        // $res = $this->service->ZipArchive($src, $dst);
        $conf_file = $this->service->create_conf_json($project_name, $version);
        $ret = $this->service->build_apk($conf_file);
        if($ret['code'])
        {
            $down_path = $_SERVER['DOCUMENT_ROOT']."/download/majiang.apk";
            rename($apk_path,$down_path);
            //unlink($down_path);
            //copy($apk_path,$down_path);
            echo '生成成功<a target="_blank" href="http://192.168.1.210/update_file/majiang.apk"> 下载安装包</a> <br>';
        }else {
            echo $ret['desc'];
        }
    }

    public function test(){
        set_time_limit(0);
        ini_set('max_input_time', '3200');
        ini_set('max_execution_time', '3200');
        $this->service->create('test');
    }
}