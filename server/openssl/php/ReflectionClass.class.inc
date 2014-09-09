<?php
class ReflectionClass
{
    public function __construct(ReflectionClass $r)
    {
        $this->_reflection = $r;

        foreach ($r->getMethods() as $method) {
            $this->_methods[] = new Reflection_Method($method);
        }
    }

    public function __call($method, $args)
    {
        if (method_exists($r, $method)) {
            return $r->{$method}($args);
        }
    }

    public function getMethods()
    {
        return $this->_methods;
    }
}

?>
