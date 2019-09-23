"""ZCM type definitions
This file automatically generated by zcm.
DO NOT MODIFY BY HAND!!!!
"""

try:
    import cStringIO.StringIO as BytesIO
except ImportError:
    from io import BytesIO
import struct

from ZcmService import ZcmService

from ZcmCameraBaslerInformation import ZcmCameraBaslerInformation

from ZcmCameraBaslerImagePresentation import ZcmCameraBaslerImagePresentation

class ZcmCameraBaslerFrame(object):
    __slots__ = ["info", "image", "synchronized", "timestamp_ns", "service"]

    def __init__(self):
        self.info = ZcmCameraBaslerInformation()
        self.image = ZcmCameraBaslerImagePresentation()
        self.synchronized = False
        self.timestamp_ns = 0
        self.service = ZcmService()

    def encode(self):
        buf = BytesIO()
        buf.write(ZcmCameraBaslerFrame._get_packed_fingerprint())
        self._encode_one(buf)
        return buf.getvalue()

    def _encode_one(self, buf):
        assert self.info._get_packed_fingerprint() == ZcmCameraBaslerInformation._get_packed_fingerprint()
        self.info._encode_one(buf)
        assert self.image._get_packed_fingerprint() == ZcmCameraBaslerImagePresentation._get_packed_fingerprint()
        self.image._encode_one(buf)
        buf.write(struct.pack(">bq", self.synchronized, self.timestamp_ns))
        assert self.service._get_packed_fingerprint() == ZcmService._get_packed_fingerprint()
        self.service._encode_one(buf)

    def decode(data):
        if hasattr(data, 'read'):
            buf = data
        else:
            buf = BytesIO(data)
        if buf.read(8) != ZcmCameraBaslerFrame._get_packed_fingerprint():
            raise ValueError("Decode error")
        return ZcmCameraBaslerFrame._decode_one(buf)
    decode = staticmethod(decode)

    def _decode_one(buf):
        self = ZcmCameraBaslerFrame()
        self.info = ZcmCameraBaslerInformation._decode_one(buf)
        self.image = ZcmCameraBaslerImagePresentation._decode_one(buf)
        self.synchronized = bool(struct.unpack('b', buf.read(1))[0])
        self.timestamp_ns = struct.unpack(">q", buf.read(8))[0]
        self.service = ZcmService._decode_one(buf)
        return self
    _decode_one = staticmethod(_decode_one)

    _hash = None
    def _get_hash_recursive(parents):
        if ZcmCameraBaslerFrame in parents: return 0
        newparents = parents + [ZcmCameraBaslerFrame]
        tmphash = (0xc1fb59f6c4809a3c+ ZcmCameraBaslerInformation._get_hash_recursive(newparents)+ ZcmCameraBaslerImagePresentation._get_hash_recursive(newparents)+ ZcmService._get_hash_recursive(newparents)) & 0xffffffffffffffff
        tmphash  = (((tmphash<<1)&0xffffffffffffffff)  + ((tmphash>>63)&0x1)) & 0xffffffffffffffff
        return tmphash
    _get_hash_recursive = staticmethod(_get_hash_recursive)
    _packed_fingerprint = None

    def _get_packed_fingerprint():
        if ZcmCameraBaslerFrame._packed_fingerprint is None:
            ZcmCameraBaslerFrame._packed_fingerprint = struct.pack(">Q", ZcmCameraBaslerFrame._get_hash_recursive([]))
        return ZcmCameraBaslerFrame._packed_fingerprint
    _get_packed_fingerprint = staticmethod(_get_packed_fingerprint)

